# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:46 jlam Exp $

.if !defined(APACHE_BUILDLINK2_MK)
APACHE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		apache
BUILDLINK_DEPENDS.apache?=	apache{,6}-1.3.*
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache

# For "apxs":
BUILD_DEPENDS+=			perl>=${PERL5_REQD}:../../lang/perl5
BUILDLINK_DEPMETHOD.apache?=	build

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
