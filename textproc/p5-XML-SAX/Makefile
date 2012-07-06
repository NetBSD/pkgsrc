# $NetBSD: Makefile,v 1.34 2012/07/06 12:37:33 sno Exp $

DISTNAME=	XML-SAX-0.99
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX/
COMMENT=	Perl interface to the SAX2 XML Parser
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	p5-XML-SAX-Base<1.07

DEPENDS+=	p5-XML-NamespaceSupport>=0.03:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-XML-SAX-Base>=1.08:../../textproc/p5-XML-SAX-Base
# included in perl>=5.6.1
#DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp

MAKE_ENV=	SKIP_SAX_INSTALL=yes
EGSUBDIR=	share/examples/p5-XML-SAX
CONF_FILES=	${EGSUBDIR}/ParserDetails.ini \
			${PERL5_INSTALLVENDORLIB}/XML/SAX/ParserDetails.ini

PERL5_PACKLIST=	auto/XML/SAX/.packlist

INSTALLATION_DIRS+=	${EGSUBDIR}

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

post-install:
	${ECHO} > ${DESTDIR:Q}${PREFIX:Q}/${EGSUBDIR}/ParserDetails.ini

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
