# $NetBSD: buildlink2.mk,v 1.7 2004/03/26 02:27:56 wiz Exp $

.if !defined(APACHE_BUILDLINK2_MK)
APACHE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		apache
BUILDLINK_DEPENDS.apache?=	apache>=2.0.49
BUILDLINK_RECOMMENDED.apache?=	apache>=2.0.49nb1
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache2
BUILDLINK_DEPMETHOD.apache?=	build

USE_PERL5?=			build	# for "apxs"

.if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.endif

EVAL_PREFIX+=				BUILDLINK_PREFIX.apache=apache
BUILDLINK_PREFIX.apache_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.apache=		include/httpd/*

.include "../../devel/apr/buildlink2.mk"

BUILDLINK_TARGETS+=	apache-buildlink

APXS?=			${BUILDLINK_PREFIX.apache}/sbin/apxs
.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs2="${APXS}"
.endif

apache-buildlink: _BUILDLINK_USE

.endif	# APACHE_BUILDLINK2_MK
