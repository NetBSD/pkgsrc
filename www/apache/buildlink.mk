# $NetBSD: buildlink.mk,v 1.4 2001/12/02 19:41:04 jlam Exp $
#
# This Makefile fragment is included by packages that use apxs from Apache.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.apache to the dependency pattern
#     for the version of apache desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(APACHE_BUILDLINK_MK)
APACHE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.apache?=	apache{,6}-1.3.*

# For "apxs":
BUILD_DEPENDS+=			perl>=${PERL5_REQD}:../../lang/perl5
BUILD_DEPENDS+=			${BUILDLINK_DEPENDS.apache}:../../www/apache

EVAL_PREFIX+=				BUILDLINK_PREFIX.apache=apache
BUILDLINK_PREFIX.apache_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.apache=			include/httpd/*/*.[ch]
BUILDLINK_FILES.apache+=		include/httpd/*.[ch]

BUILDLINK_TARGETS.apache=	apache-buildlink
BUILDLINK_TARGETS.apache+=	apache-apxs-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.apache}

APXS?=				${BUILDLINK_DIR}/sbin/apxs
.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=		--with-apxs="${APXS}"
.endif

pre-configure: ${BUILDLINK_TARGETS.apache}
apache-buildlink: _BUILDLINK_USE

_APACHE_APXS_SED=	\
	-e "s|${BUILDLINK_PREFIX.apache}\(/include/httpd\)|${BUILDLINK_DIR}\1|g"

apache-apxs-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.apache_apxs_buildlink_done;		\
	if [ ! -f $${cookie} ]; then					\
		file=sbin/apxs;						\
		${ECHO_BUILDLINK_MSG} "Creating script ${BUILDLINK_DIR}/$${file}."; \
		${MKDIR} `${DIRNAME} ${BUILDLINK_DIR}/$${file}`;	\
		${SED}	${_APACHE_APXS_SED}				\
			${BUILDLINK_PREFIX.apache}/$${file}		\
			> ${BUILDLINK_DIR}/$${file};			\
		${CHMOD} +x ${BUILDLINK_DIR}/$${file};			\
		${ECHO} ${BUILDLINK_PREFIX.apache}/$${file} >> $${cookie}; \
	fi

.endif	# APACHE_BUILDLINK_MK
