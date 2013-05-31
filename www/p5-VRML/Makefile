# $NetBSD: Makefile,v 1.24 2013/05/31 12:42:53 wiz Exp $
#

DISTNAME=	VRML-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5vrm
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=VRML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gfz-potsdam.de/~palm/software/VRML/doc
COMMENT=	Set of VRML classes for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/VRML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
