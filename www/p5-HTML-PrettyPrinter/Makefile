# $NetBSD: Makefile,v 1.19 2011/08/14 16:05:53 obache Exp $

DISTNAME=		HTML-PrettyPrinter-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
SVR4_PKGNAME=		p5hpre
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module for pretty-printing HTML

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-HTML-Tree>=3.0:../../www/p5-HTML-Tree
DEPENDS+=		p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset

PERL5_PACKLIST=		auto/HTML/PrettyPrinter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
