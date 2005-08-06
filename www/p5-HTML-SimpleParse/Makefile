# $NetBSD: Makefile,v 1.12 2005/08/06 06:19:39 jlam Exp $

DISTNAME=	HTML-SimpleParse-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hsp
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module implementing a bare-bones HTML parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/SimpleParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
