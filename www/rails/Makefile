# $NetBSD: Makefile,v 1.5 2007/04/30 21:26:03 minskim Exp $

DISTNAME=	rails-1.2.3
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/18404/
EXTRACT_SUFX=	.gem

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Framework for developing database-backed web applications

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=1.4.2:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=1.15.3:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=1.13.3:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-actionmailer>=1.3.3:../../mail/ruby-actionmailer
DEPENDS+=	${RUBY_PKGPREFIX}-actionwebservice>=1.2.3:../../www/ruby-actionwebservice

NO_BUILD=	yes

REPLACE_RUBY_DIRS=	${WRKSRC}/bin ${WRKSRC}/dispatches	\
			${WRKSRC}/lib/commands/ncgi
REPLACE_FILE_PAT=	*

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	lib/rails_generator/generators/applications/app/app_generator.rb
SUBST_SED.paths=	-e 's,:source =>.*,:source => "${PREFIX}/share/rails",g'

INSTALLATION_DIRS=	bin

.include "../../lang/ruby/modules.mk"

post-configure:
	${FIND} ${WRKSRC} -name \*.orig -exec ${RM} -f {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/rails ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/rails
	cd ${WRKSRC}/lib && ${PAX} -rwppm * ${RUBY_SITELIBDIR}/
	${INSTALL_DATA_DIR} ${PREFIX}/share/rails
.for f in CHANGELOG MIT-LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/rails
.endfor
	cd ${WRKSRC} && ${PAX} -rwppm bin builtin configs dispatches doc \
		environments fresh_rakefile helpers html \
		${PREFIX}/share/rails/

.include "../../mk/bsd.pkg.mk"
