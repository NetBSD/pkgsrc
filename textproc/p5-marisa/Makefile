# $NetBSD: Makefile,v 1.3 2015/06/12 10:51:40 wiz Exp $

.include "../../textproc/marisa/Makefile.common"

PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES+=	perl5

COMMENT=	MARISA perl module

USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	bindings/perl

PERL5_PACKLIST=		auto/marisa/.packlist

post-extract:
	${RM} ${WRKSRC}/bindings/perl/sample.pl

BUILDLINK_API_DEPENDS.marisa+=	marisa>=${PKGVERSION_NOREV}
.include "../../textproc/marisa/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
