# $NetBSD: buildlink3.mk,v 1.14 2025/10/23 20:39:37 wiz Exp $

BUILDLINK_TREE+=	akonadi-calendar

.if !defined(AKONADI_CALENDAR_BUILDLINK3_MK)
AKONADI_CALENDAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-calendar+=	akonadi-calendar>=17.12.1
BUILDLINK_ABI_DEPENDS.akonadi-calendar?=		akonadi-calendar>=23.08.4nb11
BUILDLINK_PKGSRCDIR.akonadi-calendar?=		../../time/akonadi-calendar

.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../misc/akonadi-contacts/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# AKONADI_CALENDAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-calendar
