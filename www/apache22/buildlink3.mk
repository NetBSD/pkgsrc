# $NetBSD: buildlink3.mk,v 1.12 2012/05/07 01:54:05 dholland Exp $

BUILDLINK_TREE+=	apache

.if !defined(APACHE_BUILDLINK3_MK)
APACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apache+=	apache>=2.2.3<2.3
BUILDLINK_ABI_DEPENDS.apache+=	apache>=2.2.21nb3
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache22
BUILDLINK_DEPMETHOD.apache?=	build
.if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.endif
USE_TOOLS+=	perl			# for "apxs"
CONFIGURE_ENV+=	APR_LIBTOOL=${LIBTOOL:Q}	# make apxs use the libtool we specify
MAKE_ENV+=	APR_LIBTOOL=${LIBTOOL:Q}
APXS?=		${BUILDLINK_PREFIX.apache}/sbin/apxs
.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs2=${APXS:Q}
.endif

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.endif # APACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-apache
