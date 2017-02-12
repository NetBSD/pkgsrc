#
# Copyright (c) 2016 The DragonFly Project.  All rights reserved.
#
# This code is derived from software contributed to The DragonFly Project
# by Sascha Wildner <swildner@dragonflybsd.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name of The DragonFly Project nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific, prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
# COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
# OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#

#
# Converts the output of mandoc -Ttree (run over a manual page
# with prototypes) into a small C program that can be used to
# check it.
#

($1 == "SYNOPSIS" && $2 == "(text)") {
	getline;
	if ($1 == "Sh" && ($2 == "(block-body)" || $2 == "(body)")) {
		getline;
		while ($1 != "Sh") {
			if ($2 == "(elem)") {
				if (elem == "Fn" ||
				    (elem == "Fa" && $1 != "Fa")) {
					printf ");\n"
					if (justtypedef == 0) {
						printf "#ifndef %s\n",
						    function_name;
						printf "man_%s test_%s = %s;\n",
						    function_name,
						    function_name,
						    function_name;
						printf "#endif";
					}
					printf "\n";
					justtypedef = 0;
					function_type = "";
				}
				elem = $1; # elem is now from the current line
				funcnamenext = 0;
				if (elem == "In")
					printf "#include ";
				else if (elem == "Fn")
					funcnamenext = 1;
				else if (elem == "Ft")
					firsttypenext = 1;
			} else if ($2 == "(block)" && elem == "In" &&
			    $1 != "Fo") {
				elem = "";
			} else if (match($0, "(text)") != 0) {
				if (elem == "In") {
					printf "<%s>\n", $1;
				} else if (elem == "Ft") { # function type
					if ($1 == "typedef") {
						justtypedef = 1;
						firsttypenext = 0;
					}
					gsub("^[	 ]*", "");
					gsub(" [(]text[)].*", "");
					gsub("\\\\", "");
					if (justtypedef == 1) {
						printf "\n";
					}
					if (firsttypenext == 1) {
						firsttypenext = 0;
						printf "\ntypedef ";
					}
					function_type = $0;
					printf "%s ", function_type;
				} else if (elem == "Fn") { # function name
					if (funcnamenext == 1) {
						function_name = $1;
						if (justtypedef == 1) {
							printf "%s(",
							    function_name;
						} else {
							if (function_type == "")
								printf "\ntypedef void *****";
							printf "(*man_%s)(",
							    function_name;
						}
						funcnamenext = 0;
						firstargnext = 1;
					} else { # function arguments
						gsub("^[	 ]*", "")
						gsub(" [(]text[)].*", "");
						gsub("\\\\\\\\[*][(]lp", "(");
						gsub("\\\\\\\\[*][(]rp", ")");
						if (firstargnext == 1)
							firstargnext = 0;
						else
							printf ", ";
						if (justtypedef == 0) {
							printf("\n#ifdef %s\n", function_name);
							if (index($0, " ") == 0 && $0 != "void")
								printf("int\n");
							printf("#endif\n");
						}
						printf "%s", $0;
					}
				} else if (elem == "Fa") {
					gsub("^[	 ]*", "")
					gsub(" [(]text[)].*", "");
					gsub("\\\\:", ""); # \: (see groff(7))
					if (firstargnext == 1)
						firstargnext = 0;
					else
						printf ", ";
					if (justtypedef == 0) {
						printf("\n#ifdef %s\n", function_name);
						if (index($0, " ") == 0 && $0 != "void")
							printf("int\n");
						printf("#endif\n");
					}
					printf "%s", $0;
				}
			} else if ($1 == "Fo") {
				getline; getline;
				function_name = $1;
				if (function_type == "")
					printf "\ntypedef void *****";
				printf "(*man_%s)(", function_name;
				getline;
				firstargnext = 1;
			}
			getline;
		}
		if (elem == "Fn" || elem == "Fa") {
			printf ");\n";
			if (justtypedef == 0) {
				printf "#ifndef %s\n", function_name;
				printf "man_%s test_%s = %s;\n",
				    function_name,
				    function_name,
				    function_name;
				printf "#endif\n";
			}
		}
	}
}
