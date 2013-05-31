# $NetBSD: Makefile,v 1.9 2013/05/31 12:42:35 wiz Exp $

DISTNAME=	CGI-Emulate-PSGI-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Emulate-PSGI/
COMMENT=	Perl 5 module prodiving PSGI adapter for CGI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/CGI/Emulate/PSGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
