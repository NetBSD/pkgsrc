# $NetBSD: buildlink3.mk,v 1.4 2026/01/07 08:49:20 wiz Exp $

BUILDLINK_TREE+=	libkiwix

.if !defined(LIBKIWIX_BUILDLINK3_MK)
LIBKIWIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkiwix+=	libkiwix>=14.0.0
BUILDLINK_ABI_DEPENDS.libkiwix?=	libkiwix>=14.1.1nb1
BUILDLINK_PKGSRCDIR.libkiwix?=		../../www/libkiwix

.include "../../textproc/pugixml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.endif	# LIBKIWIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkiwix
