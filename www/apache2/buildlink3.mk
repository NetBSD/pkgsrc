# $NetBSD: buildlink3.mk,v 1.4.4.1 2004/07/14 12:39:00 agc Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APACHE_BUILDLINK3_MK:=	${APACHE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apache
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napache}
BUILDLINK_PACKAGES+=	apache

.if !empty(APACHE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.apache+=	apache>=2.0.50
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache2
BUILDLINK_DEPMETHOD.apache?=	build
.  if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.  endif
.endif	# APACHE_BUILDLINK3_MK

USE_PERL5?=	build	# for "apxs"
APXS?=		${BUILDLINK_PREFIX.apache}/sbin/apxs

.include "../../devel/apr/buildlink3.mk"

.if !empty(APACHE_BUILDLINK3_MK:M+)
.  if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs2="${APXS}"
.  endif
.endif	# APACHE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
