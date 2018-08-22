# $NetBSD: buildlink3.mk,v 1.38 2018/08/22 09:42:53 wiz Exp $

BUILDLINK_TREE+=	p5-Wx

.if !defined(P5_WX_BUILDLINK3_MK)
P5_WX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-Wx+=	p5-Wx>=0.91
BUILDLINK_ABI_DEPENDS.p5-Wx+=	p5-Wx>=0.9932nb5
BUILDLINK_PKGSRCDIR.p5-Wx?=	../../x11/p5-Wx
BUILDLINK_INCDIRS.p5-Wx?=	${PERL5_SUB_INSTALLVENDORARCH}/Wx/cpp
BUILDLINK_LIBDIRS.p5-Wx?=	${PERL5_SUB_INSTALLVENDORARCH}/auto/Wx

# We want all of the arch-dependent Wx files.
BUILDLINK_CONTENTS_FILTER.p5-Wx?=	${GREP} ${PERL5_SUB_INSTALLVENDORARCH}

BUILD_DEPENDS+=	p5-Alien-wxWidgets>=0.69:../../x11/p5-Alien-wxWidgets
BUILD_DEPENDS+=	p5-ExtUtils-XSpp>=0.05:../../devel/p5-ExtUtils-XSpp

.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.endif # P5_WX_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-Wx
