# $NetBSD: Makefile,v 1.9 2016/06/08 19:24:48 wiz Exp $
#

.include "../../textproc/yamcha/Makefile.common"

PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7

COMMENT=	YamCha perl module

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/YamCha/.packlist

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=${PKGVERSION_NOREV}
.include "../../textproc/yamcha/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
