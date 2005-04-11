# $NetBSD: Makefile,v 1.16 2005/04/11 21:47:59 tv Exp $

DISTNAME=		HTML-Template-2.7
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htm
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/} \
			${MASTER_SITE_SOURCEFORGE:=html-template/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://html-template.sourceforge.net/
COMMENT=		Perl5 module to create HTML templates with simple tags

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
