# $NetBSD: Makefile,v 1.22 2011/08/14 16:05:55 obache Exp $

DISTNAME=		HTML-Table-2.08a
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5htb
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Table/
COMMENT=		Perl5 module to simplify creating HTML tables

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/HTML/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
