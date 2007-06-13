# $NetBSD: Makefile,v 1.18 2007/06/13 23:17:31 heinz Exp $

DISTNAME=	XML-SAX-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX/
COMMENT=	Perl interface to the SAX2 XML Parser

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-XML-NamespaceSupport>=0.03:../../textproc/p5-XML-NamespaceSupport
# included in perl>=5.6.1
#DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp

MAKE_ENV=	SKIP_SAX_INSTALL=yes

PERL5_PACKLIST=	auto/XML/SAX/.packlist

FILES_SUBST+=	PERL5_INSTALLVENDORLIB=${PERL5_INSTALLVENDORLIB:Q}

post-install:
	${ECHO} > ${DESTDIR:Q}${PERL5_INSTALLVENDORLIB}/XML/SAX/ParserDetails.ini

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
