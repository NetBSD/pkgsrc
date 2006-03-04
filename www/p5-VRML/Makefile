# $NetBSD: Makefile,v 1.15 2006/03/04 21:31:03 jlam Exp $
#

DISTNAME=	VRML-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5vrm
PKGREVISION=	2
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=VRML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gfz-potsdam.de/~palm/software/VRML/doc/VRML.pm.html
COMMENT=	Set of VRML classes for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/VRML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
