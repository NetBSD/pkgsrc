# $NetBSD: Makefile,v 1.21 2014/05/29 23:38:05 wiz Exp $

DISTNAME=	HTML-Clean-0.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
SVR4_PKGNAME=	p5hcl
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module that cleans up HTML code for web browsers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML/Clean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
