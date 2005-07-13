# $NetBSD: Makefile,v 1.13 2005/07/13 18:01:47 jlam Exp $

DISTNAME=		HTML-PrettyPrinter-0.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hpre
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for pretty-printing HTML

DEPENDS+=		p5-HTML-Tree>=3.0:../../www/p5-HTML-Tree
DEPENDS+=		p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML/PrettyPrinter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
