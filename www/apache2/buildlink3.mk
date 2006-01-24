# $NetBSD: buildlink3.mk,v 1.15 2006/01/24 07:32:46 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APACHE_BUILDLINK3_MK:=	${APACHE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apache
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napache}
BUILDLINK_PACKAGES+=	apache

.if !empty(APACHE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.apache+=	apache>=2.0.51
BUILDLINK_RECOMMENDED.apache+=	apache>=2.0.55nb6
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache2
BUILDLINK_DEPMETHOD.apache?=	build
.  if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.  endif
.endif	# APACHE_BUILDLINK3_MK

USE_TOOLS+=	perl			# for "apxs"
CONFIGURE_ENV+=	APR_LIBTOOL=${LIBTOOL:Q}	# make apxs use the libtool we specify
MAKE_ENV+=	APR_LIBTOOL=${LIBTOOL:Q}
APXS?=		${BUILDLINK_PREFIX.apache}/sbin/apxs

.if !empty(APACHE_BUILDLINK3_MK:M+)
.  if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs2=${APXS:Q}
.  endif
.endif	# APACHE_BUILDLINK3_MK

.include "../../devel/apr/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
