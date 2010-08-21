# $NetBSD: Makefile,v 1.2 2010/08/21 16:36:47 seb Exp $

DISTNAME=		HTML-Email-Obfuscate-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
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
