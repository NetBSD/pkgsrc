# $NetBSD: Makefile,v 1.7 2012/10/03 21:58:45 wiz Exp $

DISTNAME=	HTML-Selector-XPath-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Selector-XPath/
COMMENT=	Perl 5 CSS Selector to XPath compiler
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
BUILD_DEPENDS+= p5-Test-Base-[0-9]*:../../devel/p5-Test-Base

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTML/Selector/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
