# $NetBSD: buildlink3.mk,v 1.4 2004/01/24 03:26:48 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APACHE_BUILDLINK3_MK:=	${APACHE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apache
.endif

.if !empty(APACHE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		apache
BUILDLINK_DEPENDS.apache+=	apache{,6}-1.3.*
BUILDLINK_PKGSRCDIR.apache?=	../../lang/apache
.  if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.  else
BUILDLINK_DEPMETHOD.apache?=	build
.  endif

USE_PERL5?=	build	# for "apxs"
APXS?=		${BUILDLINK_PREFIX.apache}/sbin/apxs

.  if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs="${APXS}"
.  endif
.endif	# APACHE_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
