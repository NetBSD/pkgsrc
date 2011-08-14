# $NetBSD: Makefile,v 1.3 2011/08/14 16:05:57 obache Exp $

DISTNAME=	HTTP-OAI-3.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-OAI/
COMMENT=	API for the OAI-PMH
LICENSE=	modified-bsd

DEPENDS+=	p5-XML-LibXML>=1.60:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-SAX>=0.96:../../textproc/p5-XML-SAX
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTTP-OAI/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
