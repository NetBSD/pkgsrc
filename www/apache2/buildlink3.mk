# $NetBSD: buildlink3.mk,v 1.26 2008/01/18 05:09:48 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APACHE_BUILDLINK3_MK:=	${APACHE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apache
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napache}
BUILDLINK_PACKAGES+=	apache
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}apache

.if !empty(APACHE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.51<2.2
BUILDLINK_ABI_DEPENDS.apache+=	apache>=2.0.61nb2
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache2
BUILDLINK_DEPMETHOD.apache?=	build
.  if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.  endif
USE_TOOLS+=	perl			# for "apxs"
CONFIGURE_ENV+=	APR_LIBTOOL=${LIBTOOL:Q}	# make apxs use the libtool we specify
MAKE_ENV+=	APR_LIBTOOL=${LIBTOOL:Q}
APXS?=		${BUILDLINK_PREFIX.apache}/sbin/apxs
.  if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs2=${APXS:Q}
.  endif
.endif	# APACHE_BUILDLINK3_MK

.include "../../devel/apr0/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
