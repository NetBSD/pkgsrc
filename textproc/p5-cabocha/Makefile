# $NetBSD: Makefile,v 1.12 2016/07/26 13:38:02 mef Exp $

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
