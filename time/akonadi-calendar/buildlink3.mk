# $NetBSD: buildlink3.mk,v 1.16 2026/01/07 08:49:10 wiz Exp $

BUILDLINK_TREE+=	akonadi-calendar

.if !defined(AKONADI_CALENDAR_BUILDLINK3_MK)
AKONADI_CALENDAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-calendar+=	akonadi-calendar>=25.08.3
BUILDLINK_ABI_DEPENDS.akonadi-calendar?=	akonadi-calendar>=25.08.3nb1
BUILDLINK_PKGSRCDIR.akonadi-calendar?=		../../time/akonadi-calendar

.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../misc/akonadi-contacts/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# AKONADI_CALENDAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-calendar
