# $NetBSD: buildlink3.mk,v 1.14 2012/12/31 09:27:50 obache Exp $

BUILDLINK_TREE+=	xerces-c

.if !defined(XERCES_C_BUILDLINK3_MK)
XERCES_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=3.1.1
BUILDLINK_PKGSRCDIR.xerces-c?=		../../textproc/xerces-c

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS"
.include "../../converters/libiconv/buildlink3.mk"
.endif
.endif	# XERCES_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xerces-c
