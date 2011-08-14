# $NetBSD: Makefile,v 1.10 2011/08/14 16:05:53 obache Exp $

DISTNAME=		HTML-Element-Extended-1.18
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Element-Extended/
COMMENT=		Perl5 modules for managing HTML::Element based objects
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-HTML-Tree>=0:../../www/p5-HTML-Tree

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/HTML-Element-Extended/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
