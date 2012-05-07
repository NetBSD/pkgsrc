# $NetBSD: buildlink3.mk,v 1.20 2012/05/07 01:54:04 dholland Exp $

BUILDLINK_TREE+=	apache

.if !defined(APACHE_BUILDLINK3_MK)
APACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apache+=	apache-1.3.*
BUILDLINK_ABI_DEPENDS.apache+=	apache>=1.3.34nb5
BUILDLINK_PKGSRCDIR.apache?=	../../www/apache

.  if defined(APACHE_MODULE)
BUILDLINK_DEPMETHOD.apache+=	full
.  else
BUILDLINK_DEPMETHOD.apache?=	build
.  endif

USE_TOOLS+=	perl	# for "apxs"
APXS?=		${BUILDLINK_PREFIX.apache}/sbin/apxs

.  if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
.  endif

# required because httpd/os.h includes <dlfcn.h> when it is found by
# Apache's configure script.
.include "../../mk/dlopen.buildlink3.mk"
.endif # APACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-apache
