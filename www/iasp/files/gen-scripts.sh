#!/bin/sh
#
# $NetBSD: gen-scripts.sh,v 1.1.1.1 2003/01/01 07:03:42 jlam Exp $

IASP_CLASSPATH=
for classpath in ${WRKSRC}/lib/*.jar ${WRKSRC}/servlets; do
	destpath=`${ECHO} $classpath | ${SED} "s,${WRKSRC}/,${IASP}/,"`
	if [ -z "$IASP_CLASSPATH" ]; then
		IASP_CLASSPATH="$destpath"
	else
		IASP_CLASSPATH="$IASP_CLASSPATH:$destpath"
	fi
done

${CAT} > ${WRKSRC}/iasp-classpath.conf << EOF
# This shell script fragment defines:
#
#	IASP_CLASSPATH	the list of jar files for the iASP server environment
#
IASP_CLASSPATH="${IASP_CLASSPATH}"
EOF

${CAT} > ${WRKSRC}/iasp-common.conf << EOF
# This shell script fragment contains the common settings for JAVA_HOME
# and CLASSPATH used by the iASP control scripts.
#
. ${IASP}/iasp-classpath.conf

if [ -z "\${JAVA_HOME}" ]; then
	JAVA_HOME="${JAVA_HOME}"
fi
if [ -z "\${CLASSPATH}" ]; then
	for file in \${JAVA_HOME}/lib/classes.zip \${JAVA_HOME}/lib/tools.jar
	do
		if [ -f \$file ]; then
			if [ -z "\${IASP_CLASSPATH}" ]; then
				CLASSPATH="$file"
			else
				CLASSPATH="\${CLASSPATH}:$file"
			fi
		fi
	done
	if [ -z "\${CLASSPATH}" ]; then
		CLASSPATH="\${IASP_CLASSPATH}"
	else
		CLASSPATH="\${CLASSPATH}:\${IASP_CLASSPATH}"
	fi
fi
export CLASSPATH JAVA_HOME

if [ -z "\${JAVA}" ]; then
	JAVA="\${JAVA_HOME}/bin/java"
fi
EOF

${CAT} > ${WRKSRC}/start-server.sh << EOF
#!${SH}
. ${IASP}/iasp-common.conf
eval exec \${JAVA} servlet.http.HttpServer
EOF
chmod u+x ${WRKSRC}/start-server.sh

${CAT} > ${WRKSRC}/stop-server.sh << EOF
#!${SH}
. ${IASP}/iasp-common.conf
eval exec \${JAVA} servlet.http.HttpServerControl webserver
EOF
chmod u+x ${WRKSRC}/stop-server.sh

${CAT} > ${WRKSRC}/start-admin.sh << EOF
#!${SH}
. ${IASP}/iasp-common.conf
eval exec \${JAVA} servlet.webserver.WebHttpServer
EOF
chmod u+x ${WRKSRC}/start-admin.sh

${CAT} > ${WRKSRC}/stop-admin.sh << EOF
#!${SH}
. ${IASP}/iasp-common.conf
eval exec \${JAVA} servlet.http.HttpServerControl adminserver
EOF
chmod u+x ${WRKSRC}/stop-admin.sh

${CAT} > ${WRKSRC}/connector.sh << EOF
#!${SH}
. ${IASP}/iasp-common.conf
eval exec \${JAVA} connector.iasp_connector
EOF
chmod u+x ${WRKSRC}/connector.sh
