# $NetBSD: buildlink2.mk,v 1.3 2002/09/13 23:42:27 jlam Exp $

.if !defined(APACHE_BUILDLINK2_MK)
APACHE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		apache
BUILDLINK_DEPENDS.apache?=	apache{,6}-1.3.*
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache

USE_PERL5?=			build	# for "apxs"

.if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache?=	full
.else
BUILDLINK_DEPMETHOD.apache?=	build
.endif

EVAL_PREFIX+=				BUILDLINK_PREFIX.apache=apache
BUILDLINK_PREFIX.apache_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.apache=		include/httpd/*/*.[ch]
BUILDLINK_FILES.apache+=	include/httpd/*.[ch]

BUILDLINK_TARGETS+=	apache-buildlink

APXS?=			${BUILDLINK_PREFIX.apache}/sbin/apxs
.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs="${APXS}"
.endif

apache-buildlink: _BUILDLINK_USE

.endif	# APACHE_BUILDLINK2_MK
