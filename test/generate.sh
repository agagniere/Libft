#!/bin/env bash

global_header="launchers.h"
global_main="main.c"

echo -e "#pragma once\n" > $global_header

echo -e "#include \"${global_header}\"" > $global_main
echo -e "#include \"ft_color.h\"" >> $global_main
echo -e "#include \"ft_printf.h\"\n" >> $global_main
echo -e "int main()\n{" >> $global_main
echo -e "\tunsigned success = 0;" >> $global_main
echo -e "\tunsigned total = 0;\n" >> $global_main

generate()
{
	fun=$1
	shift
    comp_type=$1
    shift
    compare=$1
	shift
	lib=$1
	shift
	header="${fun}_tests.h"
	launcher="00_${fun}_launcher.c"

	echo -e "Generating ${fun} tests"
	echo -e "int ${fun}_launcher(void);" >> $global_header
	echo -e "\tsuccess += !${fun}_launcher(); total++;" >> $global_main
	mkdir -p $fun
	cd $fun

	# Header
	echo -e "#pragma once\n" > $header

	# Launcher
	echo -e '#include "libunit.h"' > $launcher
	echo -e "#include \"$header\"\n" >> $launcher
	echo -e "int ${fun}_launcher(void)\n{" >> $launcher
	echo -e "\tt_tests test_list[1];\n" >> $launcher
	echo -e "\ttest_list[0] = NEW_TESTS;" >> $launcher

	count=1
	for input in $@
	do
		name=${input%%|*}_test
		input=${input#*|}
		filename=$(printf "%.2i" $count)_${name}.c
		echo -e "\t$filename"
        #inlcude some headers
		echo -e "#include \"$header\"" > $filename
		echo -e '#include "comparisons.h"' >> $filename
		echo -e '#include "libft.h"' >> $filename
		echo -e "#include \"${lib}.h\"\n" >> $filename
		echo -e "int ${name}(void)\n{" >> $filename

        case "$comp_type" in
            "stdf") # There exists a standard equivalent that should behave the same way
		        echo -e "\tif (compare_${compare}(${fun}(${input}),ft_${fun}(${input})))" >> $filename
                ;;
            "custom") # A custom function to call is provided
                echo -e "\tif (${compare}($input))" >> $filename
                ;;
        esac

		echo -e "\t\treturn 0;" >> $filename
		echo -e "\telse" >> $filename
		echo -e "\t\treturn -1;\n}" >> $filename

        # Add prototype to header
		echo -e "int ${name}(void);" >> $header
        # And call to launcher
		echo -e "\tload_test(test_list, \"$(echo -e $name | tr '_' ' ')\", &$name);" >> $launcher
		let count++
	done

	echo -e "\treturn (launch_tests(\"${fun}\", test_list));\n}" >> $launcher
	cd ..
}

generate "strlen" "stdf" "int" "string" \
         'basic_string|"Hello\040World"' 'empty_string|""' 'other|"\\t!@#$%^&\\0*()"'

generate "atoi" "stdf" "int" "stdlib" \
         'basic_number|"28"' 'negative|"-8128"' 'empty|""' 'negative_zero|"-0"' \
		 'space|"\040\040-496"' 'plus_sign|"+1729\040Ramanujan"' 'tab|"\040\\t33550336\040Perfect"' \
		 'carriage_return|"\\r+877\040BellPrime"' 'form_feed|"\\f\040-16127\040CarolPrime"' \
		 'vertical_tab|"\\v7057\040CubanPrime"' 'two_plus_signs|"++3"' 'invalid_first_char|"~197\040Chen"' \
		 'leading_zeros|"000231"' 'combo|"\040\\r\\v\\n\040-00000987654321"' 'int_min|"-2147483648"' \
		 'int_max|"2147483647"'

generate "strcmp" "stdf" "int_sign" "string" \
         'basic_inequality|"string_one","string_two"' 'empty_s1|"","why"' 'empty_s2|"are",""' \
		 'empty_both|"",""' 'long_equality|"Hellllllooooooo!!!!!","Hellllllooooooo!!!!!"'

generate "modf" "custom" "test_modf" "test_modf" \
         'forty_two|42' 'four_point_two|4.2' 'pi|M_PI' 'zero|0' 'infinity|INFINITY' 'minus_infinity|-INFINITY' \
         'not_a_number|NAN' 'small|4.7e-30' 'big|7.4e30' 'tiny|3e-100' 'huge|9e180' 'subnormal|1e-320'

generate "modff" "custom" "test_modff" "test_modf" \
         'forty_twof|42' 'four_point_twof|4.2' 'pi_float|M_PI' 'zerof|0' 'infinityf|INFINITY' 'minus_infinityf|-INFINITY' \
         'not_a_numberf|NAN' 'smallf|4.7e-30' 'bigf|7.4e30'

generate "modfl" "custom" "test_modfl" "test_modf" \
         'forty_twol|42' 'four_point_twol|4.2' 'three|3' 'three_point_one|3.1' 'three_point_one_four|3.14L' 'pil|M_PI' 'zerol|0' 'infinityl|INFINITY' 'minus_infinityl|-INFINITY' \
         'not_a_numberl|NAN' 'smalll|4.7e-30' 'bigl|7.4e30' 'tinyl|1e-310' 'hugel|1e300' 'minuscule|5e-600L' 'vast|5e700L'

echo -e '\n\tft_printf("%sResult : %u / %u functions%s\\n", success == total ? COLOR(GREEN) : COLOR(RED), success, total, COLOR(NORMAL));' >> $global_main
echo -e "\treturn (success != total);\n}" >> $global_main
