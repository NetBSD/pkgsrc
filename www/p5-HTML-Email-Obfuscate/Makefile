# $NetBSD: Makefile,v 1.3 2011/08/14 16:05:53 obache Exp $

DISTNAME=		HTML-Email-Obfuscate-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5heo
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Email-Obfuscate/
COMMENT=		Perl5 module for obfuscating HTML email addresses

DEPENDS+=		p5-HTML-Parser>=3.46:../../www/p5-HTML-Parser

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/Email/Obfuscate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
