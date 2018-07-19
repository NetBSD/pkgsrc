# $NetBSD: buildlink3.mk,v 1.2 2018/07/19 14:24:10 jaapb Exp $

BUILDLINK_TREE+=	ocsigen-i18n

.if !defined(OCSIGEN_I18N_BUILDLINK3_MK)
OCSIGEN_I18N_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocsigen-i18n+=	ocsigen-i18n>=3.1.0
BUILDLINK_ABI_DEPENDS.ocsigen-i18n+=	ocsigen-i18n>=3.1.0nb1
BUILDLINK_PKGSRCDIR.ocsigen-i18n?=	../../www/ocsigen-i18n
.endif	# OCSIGEN_I18N_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocsigen-i18n
