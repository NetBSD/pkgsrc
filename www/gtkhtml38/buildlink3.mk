# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:12 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKHTML38_BUILDLINK3_MK:=	${GTKHTML38_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml38
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhtml38}
BUILDLINK_PACKAGES+=	gtkhtml38
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtkhtml38

.if !empty(GTKHTML38_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtkhtml38+=	gtkhtml38>=3.8.0
BUILDLINK_ABI_DEPENDS.gtkhtml38?=	gtkhtml38>=3.10.1nb1
BUILDLINK_PKGSRCDIR.gtkhtml38?=	../../www/gtkhtml38
.endif	# GTKHTML38_BUILDLINK3_MK

# XXX: gail is not required by the .pc file but appears as a library
# '-lgailutil' in the .la file...  I'm not sure about putting the dependency
# here.
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
