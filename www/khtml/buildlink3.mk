# $NetBSD: buildlink3.mk,v 1.23 2020/04/12 08:28:08 adam Exp $

BUILDLINK_TREE+=	khtml

.if !defined(KHTML_BUILDLINK3_MK)
KHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.khtml+=	khtml>=5.21.0
BUILDLINK_ABI_DEPENDS.khtml?=	khtml>=5.66.0nb3
BUILDLINK_PKGSRCDIR.khtml?=	../../www/khtml

.include "../../graphics/giflib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/kjs/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-khtml
