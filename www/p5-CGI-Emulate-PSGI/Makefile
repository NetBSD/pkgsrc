# $NetBSD: Makefile,v 1.1.1.1 2010/04/11 08:37:47 seb Exp $

DISTNAME=	CGI-Emulate-PSGI-0.06
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Emulate-PSGI/
COMMENT=	Perl 5 module prodiving PSGI adapter for CGI
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/CGI/Emulate/PSGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
