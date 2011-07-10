# $NetBSD: Makefile,v 1.1.1.1 2011/07/10 12:41:12 spz Exp $
#

DISTNAME=		HTML-Form-6.00
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Form/
COMMENT=		HTML Form Class that represents an HTML form element
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-HTTP-Date>=6.00:../../www/p5-HTTP-Date

USE_LANGUAGES= # empty

PERL5_PACKLIST=		auto/HTML/Form/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
