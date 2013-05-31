# $NetBSD: Makefile,v 1.7 2013/05/31 12:42:41 wiz Exp $
#

DISTNAME=		HTML-Form-6.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Form/
COMMENT=		HTML Form Class that represents an HTML form element
LICENSE=		${PERL5_LICENSE}

CONFLICTS+=		p5-libwww<6.00

DEPENDS+=		p5-HTTP-Date>=6.00:../../www/p5-HTTP-Date

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/HTML/Form/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
