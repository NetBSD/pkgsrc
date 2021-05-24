# $NetBSD: Makefile,v 1.17 2021/05/24 19:54:58 wiz Exp $

PKGREVISION= 5
.include "../../textproc/cabocha/Makefile.common"

PKGNAME=	p5-${DISTNAME}

COMMENT=	CaboCha perl module

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/CaboCha/.packlist

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
