# $NetBSD: Makefile,v 1.2 2004/12/15 17:00:30 wiz Exp $
#

DISTNAME=	WWW-Mechanize-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://search.cpan.org/dist/WWW-Mechanize/
COMMENT=	Automates web page form & link interaction

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser>=3.35:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI>=1.30:../../www/p5-URI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/WWW/Mechanize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
