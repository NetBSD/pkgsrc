# $NetBSD: Makefile,v 1.10 2019/08/11 13:24:37 wiz Exp $

DISTNAME=	File-Mork-0.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SI/SIMONW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SIMONW/File-Mork-0.3
COMMENT=	Module to read Mozilla URL history files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/File/Mork/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
