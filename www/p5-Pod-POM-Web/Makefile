# $NetBSD: Makefile,v 1.1.1.1 2008/09/07 15:05:46 seb Exp $

DISTNAME=	Pod-POM-Web-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-POM-Web/
COMMENT=	Perl 5 module providing a HTML Perldoc server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Pod/POM/Web/.packlist

DEPENDS+=	p5-Alien-GvaScript-[0-9]*:../../www/p5-Alien-GvaScript
DEPENDS+=	p5-Encode-[0-9]*:../../textproc/p5-Encode
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Module-CoreList-[0-9]*:../../devel/p5-Module-CoreList
DEPENDS+=	p5-Pod-POM>=0.17:../../textproc/p5-Pod-POM
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
