#!/bin/env bash

global_header="launchers.h"
global_main="main.c"

echo -e "#pragma once\n" > $global_header

echo -e "#include \"${global_header}\"" > $global_main
echo -e "#include \"ft_prepro/color.h\"" >> $global_main
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
	echo -e "\tt_tests test_list __attribute__((cleanup (fta_clear))) = NEW_TESTS;\n" >> $launcher

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
		echo -e "\tload_test(&test_list, \"$(echo -e $name | tr '_' ' ')\", &$name);" >> $launcher
		let count++
	done

	echo -e "\treturn (launch_tests(\"${fun}\", &test_list));\n}" >> $launcher
	cd ..
}

echo -e 'int heap_launcher(void);' >> $global_header
echo -e '\tsuccess += !heap_launcher(); total++;' >> $global_main
echo -e 'int test_printf(void);' >> $global_header
echo -e '\tsuccess += !test_printf(); total++;' >> $global_main
echo -e 'int test_prepro(void);' >> $global_header
echo -e '\tsuccess += !test_prepro(); total++;' >> $global_main
echo -e 'int test_strlen(void);' >> $global_header
echo -e '\tsuccess += !test_strlen(); total++;' >> $global_main
echo -e 'int test_atoi(void);' >> $global_header
echo -e '\tsuccess += !test_atoi(); total++;' >> $global_main
echo -e 'int test_strcmp(void);' >> $global_header
echo -e '\tsuccess += !test_strcmp(); total++;' >> $global_main
echo -e 'int test_modf_float(void);' >> $global_header
echo -e '\tsuccess += !test_modf_float(); total++;' >> $global_main
echo -e 'int test_modf_double(void);' >> $global_header
echo -e '\tsuccess += !test_modf_double(); total++;' >> $global_main
echo -e 'int test_modf_long(void);' >> $global_header
echo -e '\tsuccess += !test_modf_long(); total++;' >> $global_main

echo -e '\n\tft_printf("%sResult : %u / %u functions%s\\n", success == total ? COLOR(GREEN) : COLOR(RED), success, total, COLOR(NORMAL));' >> $global_main
echo -e "\treturn (success != total);\n}" >> $global_main
