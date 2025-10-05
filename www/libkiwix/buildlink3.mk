# $NetBSD: buildlink3.mk,v 1.2 2025/10/05 19:26:26 js Exp $

BUILDLINK_TREE+=	libkiwix

.if !defined(LIBKIWIX_BUILDLINK3_MK)
LIBKIWIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkiwix+=	libkiwix>=14.0.0
BUILDLINK_ABI_DEPENDS.libkiwix?=		libkiwix>=14.0.0nb1
BUILDLINK_PKGSRCDIR.libkiwix?=		../../www/libkiwix

.include "../../textproc/pugixml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.endif	# LIBKIWIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkiwix
