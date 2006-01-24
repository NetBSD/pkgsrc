# $NetBSD: buildlink3.mk,v 1.12 2006/01/24 07:32:45 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APACHE_BUILDLINK3_MK:=	${APACHE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apache
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napache}
BUILDLINK_PACKAGES+=	apache

.if !empty(APACHE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.apache+=	apache{,6}-1.3.*
BUILDLINK_RECOMMENDED.apache?=	apache>=1.3.34nb4
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache

.if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.else
BUILDLINK_DEPMETHOD.apache?=	build
.endif

USE_TOOLS+=	perl	# for "apxs"
APXS?=		${BUILDLINK_PREFIX.apache}/sbin/apxs

.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
.endif

# required because httpd/os.h includes <dlfcn.h> when it is found by
# Apache's configure script.
.include "../../mk/dlopen.buildlink3.mk"

.endif	# APACHE_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
