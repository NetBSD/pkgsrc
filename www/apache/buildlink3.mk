# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:45 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APACHE_BUILDLINK3_MK:=	${APACHE_BUILDLINK3_MK}+

.if !empty(APACHE_BUILDLINK3_MK:M\+)
BUILDLINK_DEPENDS.apache?=	apache{,6}-1.3.*
BUILDLINK_PKGSRCDIR.apache?=	../../lang/apache
.  if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.  else
BUILDLINK_DEPMETHOD.apache?=	build
.  endif
.endif	# APACHE_BUILDLINK3_MK

.if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	apache
USE_PERL5?=		build	# for "apxs"
.endif

.if !empty(APACHE_BUILDLINK3_MK:M\+)
BUILDLINK_PACKAGES+=	apache
APXS?=	${BUILDLINK_PREFIX.apache}/sbin/apxs
.  if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs="${APXS}"
.  endif
.endif	# APACHE_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
