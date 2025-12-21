# $NetBSD: buildlink3.mk,v 1.15 2025/12/21 19:56:12 markd Exp $

BUILDLINK_TREE+=	calendarsupport

.if !defined(CALENDARSUPPORT_BUILDLINK3_MK)
CALENDARSUPPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.calendarsupport+=	calendarsupport>=25.08.3
BUILDLINK_ABI_DEPENDS.calendarsupport?=	calendarsupport>=25.08.3
BUILDLINK_PKGSRCDIR.calendarsupport?=	../../time/calendarsupport

.include "../../time/akonadi-calendar/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# CALENDARSUPPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-calendarsupport
