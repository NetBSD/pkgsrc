# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/23 22:22:42 jnemeth Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKHTML324_BUILDLINK3_MK:=	${GTKHTML324_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml324
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhtml324}
BUILDLINK_PACKAGES+=	gtkhtml324
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtkhtml324

.if !empty(GTKHTML324_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtkhtml324+=	gtkhtml324>=3.24.0
BUILDLINK_ABI_DEPENDS.gtkhtml324?=	gtkhtml324>=3.24
BUILDLINK_PKGSRCDIR.gtkhtml324?=	../../www/gtkhtml324
.endif	# GTKHTML324_BUILDLINK3_MK

# XXX: gail is not required by the .pc file but appears as a library
# '-lgailutil' in the .la file...  I'm not sure about putting the dependency
# here.
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
