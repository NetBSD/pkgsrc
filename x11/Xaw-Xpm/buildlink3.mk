# $NetBSD: buildlink3.mk,v 1.1 2004/04/11 23:29:49 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XAW_XPM_BUILDLINK3_MK:=	${XAW_XPM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xaw-Xpm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXaw-Xpm}
BUILDLINK_PACKAGES+=	Xaw-Xpm

.if !empty(XAW_XPM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.Xaw-Xpm+=	Xaw-Xpm>=1.1
BUILDLINK_PKGSRCDIR.Xaw-Xpm?=	../../x11/Xaw-Xpm
.endif	# XAW_XPM_BUILDLINK3_MK

.include "../../mk/bsd.prefs.mk"

LIBXAW?=	-L${BUILDLINK_PREFIX.Xaw-Xpm}/lib					\
		${_COMPILER_LD_FLAG}${_OPSYS_RPATH_NAME}${BUILDLINK_PREFIX.Xaw-Xpm}/lib	\
		-L${BUILDLINK_PREFIX.xpm}/lib						\
		${_COMPILER_LD_FLAG}${_OPSYS_RPATH_NAME}${BUILDLINK_PREFIX.xpm}/lib	\
		-lXaw3d -lXpm

.include "../../graphics/xpm/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
