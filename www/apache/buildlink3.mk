# $NetBSD: buildlink3.mk,v 1.7 2004/03/29 05:05:46 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APACHE_BUILDLINK3_MK:=	${APACHE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apache
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napache}
BUILDLINK_PACKAGES+=	apache

.if !empty(APACHE_BUILDLINK3_MK:M+)
BUILDLINK_PKGBASE.apache+=	apache{,6}
BUILDLINK_DEPENDS.apache+=	apache{,6}-1.3.*
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache

.if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.else
BUILDLINK_DEPMETHOD.apache?=	build
.endif

USE_PERL5?=	build	# for "apxs"
APXS?=		${BUILDLINK_PREFIX.apache}/sbin/apxs

.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs="${APXS}"
.endif

.endif	# APACHE_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
