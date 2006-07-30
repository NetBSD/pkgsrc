# $NetBSD: module.mk,v 1.10.10.1 2006/07/30 19:21:26 salo Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install apache modules.
#
# The following targets are provided by this file:
#
# do-build		builds the module using APXS.
#
# do-install		installs the module using APXS.
#
# The following variables may be set prior to including this file:
#
# APACHE_MODULE_NAME	the name of this module, including the .so suffix.
#
# APACHE_MODULE_SRCDIR	the location of the source files for this module,
#			defaults to WRKSRC.
#
# APACHE_MODULE_SRC	the source files to be compiled for this
#			module, defaults to *.c.
#

.if !defined(_APACHE_MODULE_MK)
_APACHE_MODULE_MK=	# defined

APACHE_MODULE=		yes

.include "../../www/apache/buildlink3.mk"

APACHE_MODULE_SRCDIR?=	${WRKSRC}
APACHE_MODULE_SRC?=	*.c

.PHONY: apache-module-build
apache-module-build:
	${_PKG_SILENT}${_PKG_DEBUG} \
	cd ${APACHE_MODULE_SRCDIR} && \
		${SETENV} PATH=${PATH:Q} \
		${APXS} ${CPPFLAGS} ${LDFLAGS} \
			-c -o ${APACHE_MODULE_NAME} ${APACHE_MODULE_SRC}

do-build: apache-module-build
	${_PKG_SILENT}${_PKG_DEBUG}${DO_NADA}

.PHONY: apache-module-install
apache-module-install:
	${_PKG_SILENT}${PKG_DEBUG}					\
	cd ${APACHE_MODULE_SRCDIR} && ${APXS} -i ${APACHE_MODULE_NAME}

do-install: apache-module-install
	${_PKG_SILENT}${_PKG_DEBUG}${DO_NADA}

.endif	# _APACHE_MODULE_MK
